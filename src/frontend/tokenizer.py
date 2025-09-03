import config
import log

def tokenizer(quartzFilepath: str):

    lines = []

    try:
        with open(quartzFilepath, 'r') as openFile:
            # read in all lines from the file
            lines = openFile.readlines()
    except FileNotFoundError:
        log.fatal(f'\'{quartzFilepath}\' could not be found.')
        return
    except OSError:
        log.fatal(f'failed to open \'{quartzFilepath}\'.')
        return

    lines = list(map(lambda line: line.strip(), lines))
    lines = list(enumerate(lines, 1))
    lines = list(filter(lambda pair: pair[1] != '', lines))

    tokens = []

    for lineNumber, line in lines:
        tokens.append(getTokens(line, lineNumber))

    return tokens

def getTokens(line : str, lineNumber : int):
    
    tokens = []
    token = token_t()
    token.lineNum = lineNumber

    # read in line char by char and pattern match a token

    return tokens

class token_t:
    tokenType = ''
    tokenValue = object()
    lineNum = -1
    lineCol = -1