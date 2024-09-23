/*********************************************

CIS330: Lab 3

Implementation file for the error reporting system

*********************************************/

#include <ohno.h>
#include <string.h>
#include <stdlib.h>

static struct ohno_state *state;

/*
 * Initialize the ohno error system with the given file stream and application name.
 *
 * This should allocate and populate the state structure.
 * Make sure to make a copy of `app_name` as we'll need to use this string later when `ohno()` is called.
 *
 * Feel free to return non-zero if anything went wrong (like not having sufficient memory).
 */
int
ohno_init(FILE* where_to, const char* app_name)
{
	state = (struct ohno_state*)malloc(sizeof(struct ohno_state));
	char* s1;
	strcpy(s1, app_name);
	state->out = where_to;
	state->name = s1;
	return 0;
}

/*
 * Free any memory allocated to the ohno error system.
 *
 * You allocated memory in `ohno_init()`, now you must give it back.
 */
void
ohno_free()
{
	free(state);
}

/*
 * Report an error or warning given the current ohno error system settings (from ohno_init())
 *
 * This function should format `message` and `severity` along with the `app_name` string copied in `ohno_init()`
 * and write (print) a nice message on the saved `FILE *`.
 * The particular formating is up to you. Get creative if your like and feel free to add useful information
 * (e.g. error number or timestamp) to your report.
 */
void
ohno(const char* message, ohno_severity_t severity)
{

	
	switch(severity){
		case OHNO_WARNING:
			message = strcpy(state->name, "in WARNING");
			fprintf(state->out,"%s", message);
			break;
		case OHNO_SERIOUS:
			message = strcpy(state->name, "in SERIOUS");
			fprintf(state->out,"%s", message);
			break;
		case OHNO_FATAL:
			message = strcpy(state->name, "in FATAL");
			fprintf(state->out,"%s", message);
			break;
}
}
