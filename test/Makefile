CXX    = g++
CFLAGS = -std=c++11 -I..

SRCS = mock_hal_gpio.cpp ../drv/drv_ultrasonic.cpp test_drv_ultrasonic.cpp

test:
	$(CXX) $(CFLAGS) $(SRCS) -o run_tests && ./run_tests
