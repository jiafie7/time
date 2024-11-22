# Time

A cross-platform C++ Time utility class that provides robust time-related functionalities, including current time retrieval, time differences, and formatted output. The class is designed to work seamlessly on both Windows and Linux platforms.

## Features

- **Cross-Platform Current Time Retrieval**: Retrieve the current **year**, **month**, **day**, **hour**, **minute**, and **second**.
- **Time Difference Calculation**: Overloads the - operator to compute the difference between two Time objects in microseconds.
- **Cross-Platform Sleep**: Provides a sleep() function to pause execution for a specified number of milliseconds.
- **Formatted Time Output**: Format and print the current time in customizable formats (e.g., YYYY-MM-DD HH:MM:SS).

## Getting Started

1. Prerequisites

- C++ 11 or later

2. Clone the Repository

```bash
git clone https://github.com/jiafie7/time.git
cd time
```

3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

1. Example code

```c
#include <iostream>

#include "utility/time.h"

using namespace melon::utility;

int main()
{
  Time t1;
  std::cout << "t1: " << t1.format("%Y-%m-%d %H:%M:%S") << '\n';

  Time::setSleep(2000);

  Time t2;
  std::cout << "t2: " << t2.format("%Y-%m-%d %H:%M:%S") << '\n';

  std::cout << "Time interval between t1 and t2 is " << t2 - t1 << " microseconds" << '\n';

  return 0;
}
```

2. Run the Example

```bash
./main
```

3. Output

```c
t1: 2024-11-22 14:53:03
t2: 2024-11-22 14:53:05
Time interval between t1 and t2 is 2.00512e+06 microseconds
```

## API Reference

### Member Functions

- int getYear(): Returns the current year.
- int getMonth(): Returns the current month (1-12).
- int getDay(): Returns the current day of the month (1-31).
- int getHour(): Returns the current hour (0-23).
- int getMinute(): Returns the current minute (0-59).
- int getSecond(): Returns the current second (0-59).
- std::string format(const std::string& format) const: Returns the current time formatted according to the specified format string.

### Static Functions

- void setSleep(int milliseconds): Pauses execution for the specified duration.

### Operator Overloading

- double operator-(const Time& other) const: Computes the time difference between two Time objects in microseconds.

## Cross-Platform Implementation

The Time class uses platform-specific APIs to ensure compatibility with both Windows and Linux:

- **Windows**: Utilizes SYSTEMTIME and GetLocalTime() for time retrieval, and Sleep() for delays.
- **Linux**: Utilizes gettimeofday() and usleep() for time retrieval and delays.

Code automatically selects the appropriate implementation using preprocessor directives:

```c
#ifdef WIN32
// Windows-specific implementation
#else
// Linux-specific implementation
#endif
```

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m "Add feature-name"`.
4. Push to your branch: `git push origin feature-name`.
5. Open a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
