import sys

import lexer
import config

import log

arguments = sys.argv[1:]

def main():

    processFlags()

    log.printLog()

    if log.filterFatals():
        exit()

    log.clearLog()

    # print('Parsed Flags:')
    # print(f'- Output Filepath:  {config.OUTPUT_FILEPATH}')
    # print(f'- Enable Werror:    {config.ENABLE_WERROR}')
    # print('')
    # print('Parsed Files: ')
    # for file in config.QUARTZ_FILES:
    #     print(f'- {file}')
    # print('')

    for filepath in config.QUARTZ_FILES:
        lexer.startLexer(filepath)
        
        log.printLog()

        if log.filterFatals():
            exit()
        
    
def processFlags():
    
    if '-h' in arguments or '--help' in arguments:
        printHelp()
        exit()

    if '-werror' in arguments:
        config.ENABLE_WERROR = True
    else:
        config.ENABLE_WERROR = False

    if '-o' in arguments or '--output' in arguments:
        
        index = -1
        
        try:
            index = arguments.index('-o')
        except ValueError:
            index = arguments.index('--output')

        index += 1

        if len(arguments[index:]) == 0 or arguments[index].startswith('-'):
            log.error(f'missing filename after \'{arguments[index - 1]}\'.')
        else:
            config.OUTPUT_FILEPATH = arguments[index]

    for arg in arguments:
        if arg.endswith('.qz') and len(arg) > 3:
            config.QUARTZ_FILES.add(arg)

    if len(config.QUARTZ_FILES) == 0:
        log.fatal('no input files passed.')
        return

def printHelp():
    print('Usage: qzc [Options] file...')
    print('')
    print('Options:')
    print('  --output  -o    changes the filepath of the output file.')
    print('  -werror         enables treating warnings as errors (NOT FUNCTIONAL)')
    print('  --help    -h    displays this menu')
    print('')

main()