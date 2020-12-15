import queue
from threading import Thread
from time import sleep


# Constants
MAX_QUEUE_SIZE: int = 100
# Change this for more fibonacci values
MAX_ITERATIONS: int = 10

# Inputs values for each process
inputs: dict = {
    'add0': queue.Queue(MAX_QUEUE_SIZE),
    'add1': queue.Queue(MAX_QUEUE_SIZE),
    'delay0': queue.Queue(MAX_QUEUE_SIZE),
    'delay1': queue.Queue(MAX_QUEUE_SIZE),
    'split': queue.Queue(MAX_QUEUE_SIZE),
}


def add(name: str, i: int = 0) -> None:
    """This function adds to numbers from a queue.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """
    while i < MAX_ITERATIONS:
        # Check if the queues are not empty
        if not inputs[name + '0'].empty() and not inputs[name + '1'].empty():
            # Compute the add operation
            num1: int = inputs[name + '0'].get(0)
            num2: int = inputs[name + '1'].get(0)

            inputs['delay1'].put(num1 + num2)
            i += 1

        sleep(0.25)

def delay0(name: str, i: int = 0) -> None:
    """This function delays the insertion of a number into a queue.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """
    while i < MAX_ITERATIONS:
        if inputs[name].empty():
            # Write 0 in the first iteration
            if i == 0:
                inputs['add1'].put(0)
                i += 1
        else:
            # Set the input in the operand
            inputs['add1'].put(inputs[name].get(0))
            i += 1

        sleep(0.5)

def delay1(name: str, i: int = 0) -> None:
    """This function delays the insertion of a number into a queue.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """
    while i < MAX_ITERATIONS:
        if inputs[name].empty():
            # Write 1 in the first iteration
            if i == 0:
                inputs['split'].put(1)
                i += 1
        else:
            # Set the input in the operand
            inputs['split'].put(inputs[name].get(0))
            i += 1

        sleep(0.5)

def split(name: str, i: int = 0) -> None:
    """This function splits the result to write it into two different
    queues.

    Params
    ------------------------------------------------------------------
        name: str.
            Queque name.
        i: int.
            Current iteration.
    """
    while i < MAX_ITERATIONS:
        if not inputs[name].empty():
            # Read the input
            value: int = inputs[name].get(0)

            # Write the input in the operand
            inputs['add0'].put(value)
            # Write into the delay0 queue
            inputs['delay0'].put(value)
            i += 1

            print(value)

        sleep(0.5)


if __name__ == "__main__":
    process_names: list = ['add', 'delay0', 'split', 'delay1']

    # Create all threads and start them
    thread_list: list = [Thread(target=eval(name), args=(name, )) for name in process_names]

    for thread in thread_list:
        thread.start()
