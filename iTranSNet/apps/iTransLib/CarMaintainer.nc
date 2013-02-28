interface CarMaintainer
{
	command result_t carReached();
	event result_t carReachedDone();
	command result_t carLeft();
	event result_t carLeftDone();
}
