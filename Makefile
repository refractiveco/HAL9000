# BUILD THE FRAMEWORK
# compiler flags:
CFLAGS  = -Wall -Wextra
INCLUDES = -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui -lopencv_objdetect -lopencv_imgcodecs
LIBS = ./libs/gestures.cpp -I ./libs

# Build all
all: livecap vidcap
	$(livecap)
	$(vidcap)

# build livecap
livecap: ./livecap/livecap.cpp ./libs/gestures.cpp
	g++ ./livecap/livecap.cpp $(LIBS) -o ./build/livecap $(INCLUDES) $(CFLAGS)

# build vidcap
vidcap: ./vidcap/vidcap.cpp ./libs/gestures.cpp
	g++ ./vidcap/vidcap.cpp $(LIBS) -o ./build/vidcap $(INCLUDES) $(CFLAGS)

clean:
	$(RM) ./build/livecap
	$(RM) ./build/vidcap
