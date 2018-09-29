CC=g++
OUT=build
CREATE_DIR=mkdir -p
REMOVE_DIR=rm -rdf

tests: out
	$(CC) tests/*.cpp -o $(OUT)/tests
	$(OUT)/tests

out:
	$(CREATE_DIR) $(OUT)

clean:
	$(REMOVE_DIR) $(OUT)
