
#!/usr/bin/python3
""" rain problem """


def rain(walls):
    """ calculate rain drops """
    raindrops = 0
    if len(walls) < 1:
        return 0
    for i in range(len(walls)):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        raindrops += min(left, right) - walls[i]
    return raindrops