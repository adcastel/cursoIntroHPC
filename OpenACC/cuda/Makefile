CUDA_COMPILER=/state/partition1/soft/cuda-8.0/bin/nvcc


FILE=basic_cuda

all: $(FILE) 


$(FILE):
	$(CUDA_COMPILER) $(FILE).cu -o $(FILE) 

clean:
	rm -f *o *.ptx $(FILE) 

