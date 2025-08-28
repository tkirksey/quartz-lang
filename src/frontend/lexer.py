import config
import log

def startLexer(quartzFilepath: str):

    print('< -------------------------------- >')
    print(f'Lexing: {quartzFilepath}')
    print('< -------------------------------- >')

    try:
        with open(quartzFilepath, 'r') as openFile:
            # read in all lines from the file
            lines = openFile.readlines()

            # remove leading an trailing whitespace
            lines = list(map(str.strip, lines))

            # loop over all lines
            for line in lines:

                # check if line contains comment
                if line.find('//') != -1:

                    # check if comment is not part of string literal
                    if line.find("\"") == -1 or line.find("\"") > line.find('//'):
                        # slice comment off of line
                        line = line[:line.find('//')]

                    

                # if line is empty, move on to next line
                if len(line) == 0:
                    continue

                print(line)

    except FileNotFoundError:
        log.fatal(f'\'{quartzFilepath}\' could not be found.')
    except OSError:
        log.fatal(f'failed to open \'{quartzFilepath}\'.')

