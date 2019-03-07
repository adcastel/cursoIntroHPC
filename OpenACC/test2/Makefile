OPT=-fast
ACC=-acc -ta=nvidia:cc20
CUDA_VERSION_PATH=/state/partition1/soft/cuda-8.0/
OPENACC_COMPILER=pgcc


FILE=saxpyOpenACC

all: $(FILE) 


$(FILE):
	$(OPENACC_COMPILER) $(ACC) $(OPT) -o $(FILE) $(FILE).c -Minfo -L$(CUDA_VERSION_PATH)lib64 -lcudart 


clean:
	rm -f *o *.ptx $(FILE) 

