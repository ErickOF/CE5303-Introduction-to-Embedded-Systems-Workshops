from PIL import Image
import numpy as np
import queue
from threading import Thread
from time import sleep


# Constants
MAX_QUEUE_SIZE: int = 100
# Change this for more fibonacci values
MAX_ITERATIONS: int = 263

str_data: str = "2173 1 93 3 92 5 64 4 1 10 13 4 61 20 10 8 54 11 2 12 11 7 11 4 35 12 5 12 11 6 11 4 34 12 7 11 11 7 9 5 33 13 12 8 11 6 8 5 33 9 17 7 11 6 7 6 33 8 18 8 10 6 7 6 32 9 18 10 8 6 7 4 34 9 19 9 7 7 7 4 33 10 21 7 8 6 6 5 33 10 21 7 8 6 6 5 33 10 22 6 7 7 5 6 33 10 20 8 7 7 5 6 32 11 19 9 7 5 7 5 32 10 21 8 6 7 7 4 33 10 21 8 5 8 6 5 32 11 20 9 4 9 4 7 33 12 18 9 4 9 3 6 35 13 17 9 3 9 3 6 9 3 22 18 12 10 3 9 3 7 8 5 22 17 11 10 2 11 2 7 8 5 22 20 8 23 1 9 5 5 24 22 1 1 2 26 1 7 6 6 24 59 5 6 26 58 4 6 28 57 3 1 1 5 29 66 32 63 32 61 36 59 37 57 38 56 40 55 42 52 43 52 43 50 46 47 49 45 50 38 1 1 1 1 53 36 59 33 63 32 63 32 64 30 68 28 71 24 75 20 81 13 2174"
list_data: list = [int(i) for i in str_data.split(" ")]
output_data: list = []

# Inputs values for each process
inputs: dict = {
    'repr0': queue.Queue(MAX_QUEUE_SIZE),
    'repr1': queue.Queue(MAX_QUEUE_SIZE)
}


def read_value(name: str, i: int = 0) -> None:
    """This function reads from the data list.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """

    while i < MAX_ITERATIONS:

        # Compute the add operation
        # num1: int = inputs[name + '0'].get(0)
        # num2: int = inputs[name + '1'].get(0)

        inputs['repr0'].put(list_data[i])
        i += 1

        sleep(0.1)


def alt(name: str, i: int = 0) -> None:
    """This function alternates 1s and 0s to the output.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """
    value: int = 1

    while i < MAX_ITERATIONS:
        # Check if the queues are not empty
        # if not inputs[name].empty():
            # Compute the add operation
            # num: int = inputs[name].get(0)

        inputs['repr1'].put(value)
        value = 1 - value
        i += 1

        sleep(0.1)

def repr(name: str, i: int = 0) -> None:
    """This function replicates a value for a number of times.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """
    while i < MAX_ITERATIONS:
        if not inputs[name + '0'].empty() and not inputs[name + '1'].empty():

            # Set the input in the operand
            temp: int = inputs[name + '1'].get(0)

            for j in range(inputs[name + '0'].get(0)):
                output_data.append(temp)
            i += 1

        sleep(0.1)

# def split0(name: str, i: int = 0) -> None:
#     """This function splits the result to write it into two different
#     queues.

#     Params
#     ------------------------------------------------------------------
#         name: str.
#             Queque name.
#         i: int.
#             Current iteration.
#     """
#     while i < MAX_ITERATIONS:
#         if not inputs[name].empty():
#             # Read the input
#             value: int = inputs[name].get(0)

#             # Write the input in the operand
#             inputs['add00'].put(value)
#             i += 1

#             print(value)

#         sleep(0.5)

# def split1(name: str, i: int = 0) -> None:
#     """This function splits the result to write it into two different
#     queues.

#     Params
#     ------------------------------------------------------------------
#         name: str.
#             Queque name.
#         i: int.
#             Current iteration.
#     """
#     while i < MAX_ITERATIONS:
#         if not inputs[name].empty():
#             # Read the input
#             value: int = inputs[name].get(0)

#             # Write the input in the operand
#             inputs['add01'].put(value)
#             inputs['add1'].put(value)
#             i += 1

#         sleep(0.5)


if __name__ == "__main__":
    process_values: list = [['read_value', ''],
                            ['alt', ''],
                            ['repr', 'repr']]

    # Create all threads and start them
    thread_list: list = [Thread(target=eval(values[0]), args=values[1:]) for values in process_values]

    for thread in thread_list:
        thread.start()

    for thread in thread_list:
        thread.join()

    # print(output_data)

    for i in range(len(output_data)):
        if output_data[i] == 1:
            output_data[i] = 255

    bitmap = np.array(output_data)
    bitmap = np.array(bitmap).reshape([96, 96])
    bitmap = bitmap.astype(np.uint8)
    im = Image.fromarray(bitmap)
    # im.show()
    im.save('result.jpg', 'jpeg')

