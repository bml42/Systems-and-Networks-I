mt-collatz.exe

Designed by:	Ali Al-Senan
		Benjamin Linam

The only problem encountered during design of the project was placement of clock_gettime().  Originally the times were collected before pthread_create() and after pthread_join().  This resulted in incorrect times with excessive variance in collected data after each run of the program.  Moving the clock times to before and after the thread operations resulted in times that more acurately reflected the actual runtime.  