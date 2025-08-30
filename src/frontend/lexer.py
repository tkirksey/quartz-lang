import config
import log

def startLexer(quartzFilepath: str):

    lines = []

    try:
        with open(quartzFilepath, 'r') as openFile:
            # read in all lines from the file
            lines = openFile.readlines()

            # give lines associated line numbers
            lines = list(enumerate(lines, 1))

            # remove leading and trailing whitespace
            lines = list(map(lambda line: (line[0], line[1].strip()), lines))

            # fileter for whole line comments
            lines = list(filter(lambda line: line[1].find('//') != 0, lines))

            # check for quote pairs
            for i, line in lines:
                if checkDoubleQuotePairs(line) == False:
                    log.error(f'missing closing double quote on line {i} in \'{quartzFilepath}\'')

                err = checkSingleQuotePairs(line)

                if err == 1:
                    log.error(f'missing closing single quote on line {i} in \'{quartzFilepath}\'')

                if err == 2:
                    log.error(f'too many character between single quote on line {i} in \'{quartzFilepath}\'')

                if err == 3:
                    log.error(f'empty single quote on line {i} in \'{quartzFilepath}\'')

            if log.filterErrors():
                return

            # filter partial comments
            lines = list(map(lambda line: (line[0], stripPartialComments(line[1])), lines))

            # filter blank lines
            lines = list(filter(lambda line: line[1] != '', lines))

    except FileNotFoundError:
        log.fatal(f'\'{quartzFilepath}\' could not be found.')
        return
    except OSError:
        log.fatal(f'failed to open \'{quartzFilepath}\'.')
        return

def stripPartialComments(line: str) -> str:

    commentStart = line.find('//')

    if(commentStart == -1):
        return line
    
    quoteStart = line.find('\"')

    # if there is no " character, 
    # then it is safe the say that 
    # after the commentStart is a comment
    # and should be ignored.

    if(quoteStart == -1):
        return line[0:commentStart].strip()
    
    quoteEnd = line.find("\"", (quoteStart + 1))

    # if '//' is inside of a string literal,
    # handle the case
    if quoteStart < commentStart and commentStart < quoteEnd:
        firstHalf = line[0:(quoteEnd + 1)]
        secondHalf = stripPartialComments(line[(quoteEnd + 1):])
        return firstHalf + secondHalf
    
    # otherwise just strip comment like normal
    return line[0:commentStart].strip()

def checkDoubleQuotePairs(line: str) -> bool:

    quoteStart = line.find('\"')

    if quoteStart == -1:
        return True
    
    quoteEnd = line.find('\"', (quoteStart + 1))

    while line[(quoteEnd - 1)] == '\\':
        quoteEnd = line.find('\"', (quoteEnd + 1))

    if quoteEnd == -1:
        return False
    
    return checkDoubleQuotePairs(line[(quoteEnd + 1):])

def checkSingleQuotePairs(line: str) -> int:

    quoteStart = line.find('\'')

    if quoteStart == -1:
        return 0
    
    quoteEnd = line.find('\'', (quoteStart + 1))

    if quoteEnd == -1:
        return 1
    
    sizeOfQuote = (quoteEnd - quoteStart) - 1

    if sizeOfQuote > 2:
        return 2
    
    if sizeOfQuote == 2:
        if line[quoteStart + 1] == '\\':
            return 0
        else:
            return 2
        
    if sizeOfQuote == 0:
        return 3
    
    return checkSingleQuotePairs(line[(quoteEnd + 1):])

