# 0x10. Rain

## Specializations - Interview Preparation ― Algorithms

![Rain](https://i.imgur.com/HIiPzD1.png)


Technical interview preparation:

## Tasks

Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains.

- Prototype: def rain(walls)
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return 0.

```
    user@ubuntu:~/0x10$ cat 0_main.py
    #!/usr/bin/python3
    """
    0_main
    """
    rain = __import__('0-rain').rain

    if __name__ == "__main__":
        walls = [0, 1, 0, 2, 0, 3, 0, 4]
        print(rain(walls))

    user@ubuntu:~/0x10$ 
    user@ubuntu:~/0x10$ ./0_main.py
    6
    user@ubuntu:~/0x10$ 
```
