GPP:=g++

SRC_DIR:=src/
INC_DIR:=include/
GPP_FLAG:= -std=c++14 -I ${INC_DIR}

TARGET:=main
TARGET_SRC:=${SRC_DIR}${TARGET}.cpp
TARGET_OBJ:=${TARGET_SRC:.cpp=.o}

SRC_LIST:=${TARGET_SRC} ${SRC_DIR}node.cpp
OBJ_LIST:=${SRC_LIST:.cpp=.o}

all: ${TARGET}

${TARGET}: ${OBJ_LIST}
	${GPP} ${GPP_FLAG} -o $@ $^
	
${TARGET_OBJ}:
	${GPP} ${GPP_FLAG} -c ${TARGET_SRC} -o ${TARGET_OBJ}

${SRC_DIR}node.o:
	${GPP} ${GPP_FLAG} -c ${SRC_DIR}node.cpp -o ${SRC_DIR}node.o

clean:
	rm ${TARGET}
	rm ${OBJ_LIST}
