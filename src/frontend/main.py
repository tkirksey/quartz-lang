import sys
from lexer import lexer

arguments = sys.argv[1:]

quartzFiles = set()
outputFilepath = "a.out"
enableWerror = False

def main():
    
    processFlags()
    
    global enableWerror
    global outputFilepath
    global quartzFiles

    print("Parsed Flags:")
    print(f"- Output Filepath:  {outputFilepath}")
    print(f"- Enable Werror:    {enableWerror}")
    print("")
    print("Parsed Files: ")
    for file in quartzFiles:
        print(f"- {file}")
    print("")

    lexer(quartzFiles=quartzFiles, enableWerror=enableWerror)
    
def processFlags():

    global enableWerror
    global outputFilepath
    global quartzFiles

    if len(arguments) == 0:
        print("[Error]: no input files passed.")
        exit()
    
    if "-h" in arguments or "--help" in arguments:
        printHelp()
        exit()

    if "--werror" in arguments:
        enableWerror = True
    else:
        enableWerror = False

    if "-o" in arguments or "--output" in arguments:
        
        index = -1
        
        try:
            index = arguments.index("-o")
        except ValueError:
            index = arguments.index("--output")

        index += 1

        if len(arguments[index:]) == 0:
            print("[Warning]: no output filepath passed with '--output/-o' flag.")
        else:
            outputFilepath = arguments[index]

    for arg in arguments:
        if arg.endswith(".qz") and len(arg) > 3:
            quartzFiles.add(arg)

def printHelp():
    print("Usage: qzc [Options] file...")
    print("")
    print("Options:")
    print("  --output  -o    changes the filepath of the output file.")
    print("  --werror        enables treating warnings as errors (NOT FUNCTIONAL)")
    print("  --help    -h    displays this menu")
    print("")

main()