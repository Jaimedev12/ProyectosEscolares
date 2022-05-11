from turtle import *
import math

shape('turtle)
color('purple', 'cyan')

begin_fill() # Call before drawing

while True:
    forward(200)
    left(170)
    if abs(pos()) < 1:
        break
    
end_fill()
done()
