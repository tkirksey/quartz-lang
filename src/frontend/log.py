_LOG = []

def clearLog():
    _LOG.clear()

def printLog():
    for msg in _LOG:
        print(f'[{msg[0]}] {msg[1]}')

def filterWarnings():
    return list(filter(lambda x: x[0].upper() == 'WARNING', _LOG))

def filterErrors():
    return list(filter(lambda x: x[0].upper() == 'ERROR', _LOG))

def filterFatals():
    return list(filter(lambda x: x[0].upper() == 'FATAL', _LOG))

def filterTag(tag: str):
    return list(filter(lambda x: x[0].upper() == tag.upper(), _LOG))

def warning(message: str):
    _LOG.append(("WARNING", message))

def error(message: str):
    _LOG.append(("ERROR", message))

def fatal(message: str):
    _LOG.append(("FATAL", message))

def custom(tag: str, message: str):
    _LOG.append((tag, message))