def lexer(quartzFiles: set[str], enableWerror: bool):
    for filepath in quartzFiles:
        print(f"Lexing: {filepath}")
        
        with open(filepath, "r") as file:
            for line in file:
                print(line.strip())
            

