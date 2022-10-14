import math

def quadratic_equation(a, b=0, c=0):
    delta = b ** 2 - 4 * a * c
    if delta < 0:
        return 'Brak rozwiazania'
    elif delta == 0:
        if a != 0:
            x0 = -b/2 * a
            return x0
    else:
        if a != 0:
            x1 = (- b - math.sqrt(delta))/2 * a
            x2 = (- b + math.sqrt(delta))/2 * a
            return x1,x2
quadratic_equation(1,4,1)