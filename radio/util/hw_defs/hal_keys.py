
# Trims:
#  TRIMS_GPIO_REG_[trim]
#  TRIMS_GPIO_PIN_[trim]
#
# where 'trim' is one of:
#
#   (-)    (+)   
#  'LHL', 'LHR',
#  'LVD', 'LVU',
#  'RVD', 'RVU',
#  'RHL', 'RHR',
#  'LSD', 'LSU', T4
#  'RSD', 'RSU', T5

TRIMS = [
    { "name": "T1", "dec": "LHL", "inc": "LHR", "input": "LH" },
    { "name": "T2", "dec": "LVD", "inc": "LVU", "input": "LV" },
    { "name": "T3", "dec": "RVD", "inc": "RVU", "input": "RV" },
    { "name": "T4", "dec": "RHL", "inc": "RHR", "input": "RH" },
    { "name": "T5", "dec": "LSD", "inc": "LSU" },
    { "name": "T6", "dec": "RSD", "inc": "RSU" },
]

KEYS = [
    { "name": "MENU", "key": "KEY_MENU", "label": "Menu" },
    { "name": "EXIT", "key": "KEY_EXIT", "label": "Exit" },
    { "name": "ENTER", "key": "KEY_ENTER", "label": "Enter" },

    { "name": "PAGE", "key": "KEY_PAGE", "label": "Page" },
    { "name": "PAGEUP", "key": "KEY_PAGEUP", "label": "PgUp" },
    { "name": "PAGEDN", "key": "KEY_PAGEDN", "label": "PgDn" },

    { "name": "UP", "key": "KEY_UP", "label": "Up" },
    { "name": "DOWN", "key": "KEY_DOWN", "label": "Down" },

    { "name": "LEFT", "key": "KEY_LEFT", "label": "Left" },
    { "name": "RIGHT", "key": "KEY_RIGHT", "label": "Right" },

    { "name": "PLUS", "key": "KEY_PLUS", "label": "Plus" },
    { "name": "MINUS", "key": "KEY_MINUS", "label": "Minus" },

    { "name": "MDL", "key": "KEY_MODEL", "label": "MDL" },
    { "name": "TELE", "key": "KEY_TELE", "label": "TELE" },
    { "name": "SYS", "key": "KEY_SYS", "label": "SYS" },

    { "name": "SHIFT", "key": "KEY_SHIFT", "label": "Shift" },
]

class Key:

    def __init__(self, gpio, pin):
        self.gpio = gpio
        self.pin = pin

class Trim:

    def __init__(self, name, dec, inc):
        self.name = name
        self.dec = dec
        self.inc = inc

def get_trim_switch(hw_defs, tag):

    gpio = f'TRIMS_GPIO_REG_{tag}'
    pin  = f'TRIMS_GPIO_PIN_{tag}'

    if (gpio in hw_defs) and (pin in hw_defs):
        return Key(hw_defs[gpio], hw_defs[pin])

    return None


def parse_trims(hw_defs):

    trims = []
    for t in TRIMS:

        name = t['name']
        dec = get_trim_switch(hw_defs, t['dec'])
        inc = get_trim_switch(hw_defs, t['inc'])

        if dec and inc:
            trims.append(Trim(name, dec, inc))

    return trims
        
    
def parse_keys(hw_defs):

    keys = []
    for k in KEYS:

        name = k['name']
        gpio = f'KEYS_GPIO_REG_{name}'
        pin  = f'KEYS_GPIO_PIN_{name}'

        if (gpio in hw_defs) and (pin in hw_defs):
            key = Key(hw_defs[gpio], hw_defs[pin])
            key.key = k['key']
            key.name = name
            key.label = k['label']
            keys.append(key)

    return keys