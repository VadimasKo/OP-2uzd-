main: GenerateRecords.o Classes.o Main.o
	cd ProjectFiles && g++ -o my_program.exe GenerateRecords.o Classes.o Main.o && mv my_program.exe ../my_program.exe
GenerateRecords.o:
	cd Source && g++ -c GenerateRecords.cpp && mv GenerateRecords.o ../ProjectFiles/GenerateRecords.o
Classes.o:
	cd Source && g++ -c Classes.cpp && mv Classes.o ../ProjectFiles/Classes.o
Main.o:
	cd Source && g++ -c Main.cpp && mv Main.o ../ProjectFiles/Main.o