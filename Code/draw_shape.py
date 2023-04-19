import turtle

# Function to handle the exception where an invalid file name is entered
def openFile():

    # Initialize a false boolean
    file_exists = False

    # Run until the boolean becomes true
    while file_exists == False:
        
        # Get the name of the desired file
        fname = input("Enter a file name: ")
        
        # Try to open the file and set the boolean to true
        # NOTE: I have to open the file with specific encoding because of the way I downloaded movie file
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
    shape_file = openFile()

    # Open the Turtle window
    window = turtle.Screen()
    draw = turtle.Turtle()

    # Loop through the command file
    for line in shape_file:
    
        # Strip the "\n" character from each line
        line = line.strip()

        command, value = line.split(',')
        value = int(value)

        if command == 'F':
            draw.fd(value)
        elif command == 'B':
            draw.bk(value)
        elif command == 'L':
            draw.left(value)
        elif command == 'R':
            draw.right(value)

    # Close the window
    window.exitonclick()

def main():
    draw_shape()
    return
