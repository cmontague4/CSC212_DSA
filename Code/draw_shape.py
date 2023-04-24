import turtle
import random

# Function to handle the exception where an invalid file name is entered
def open_file():

    # Initialize a false boolean
    file_exists = False

    # Run until the boolean becomes true
    while file_exists == False:
        
        # Get the name of the desired file
        fname = input("Enter a file name: ")
        
        # Try to open the file and set the boolean to true
        try:
            shape_file = open(fname, 'r', encoding = 'utf-8-sig')
            file_exists = True
        # If an invalid name is entered, tell the user to retry
        except FileNotFoundError:
            print("Invalid file name, please enter a valid file name.")

    # Return the valid file
    return shape_file

# Function to get the data from an input file name
def draw_shape():

    # Get the file name from the user and open the file if it's valid
    shape_file = open_file()

    # Ask the user if they'd like their shapes to be multi-colored
    while True:
        randomize = input("Randomize colors? Enter yes or no: ").lower()
        if randomize == "yes" or randomize == "no":
            break
        else:
            print("Invalid response, please type 'yes' or 'no'.")

    # Open the Turtle window
    window = turtle.Screen()
    draw = turtle.Turtle()
    draw.speed(0)

    # Read the first line of the file, containing directions to ensure the shape is centered
    first_line = shape_file.readline()
    first_line = first_line.strip()
    horizontal,vertical = first_line.split(',')
    horizontal = float(horizontal)
    vertical = float(vertical)

    # Move the turtle without drawing
    draw.penup()
    draw.goto(horizontal,vertical)
    draw.pendown()

    # Set the turtle's color setting mode to the 0-255 RGB values
    turtle.colormode(255)

    # Loop through the command file
    for line in shape_file:

        # Strip the "\n" character from each line
        line = line.strip()

        # Tokenize the Turtle command and its corresponding value
        command, value = line.split(',')
        value = float(value)

        # Randomize the turtle's color if the user chose to
        if randomize == "yes" and (command == 'F' or command == 'B'):
            draw.color(random.randint(0, 255),random.randint(0, 255),random.randint(0, 255))
        
        # Draw the command using F = forward, B = lift pen and move backward, L = turn left, R = turn right
        if command == 'F':
            draw.fd(value)
        elif command == 'B':
            draw.color(255,255,255)
            draw.penup()
            draw.bk(value)
            draw.pendown()
            draw.color(0,0,0)
        elif command == 'L':
            draw.left(value)
        elif command == 'R':
            draw.right(value)

    # Close the window when the user clicks the mouse
    window.exitonclick()

# Call to draw_shape
draw_shape()
