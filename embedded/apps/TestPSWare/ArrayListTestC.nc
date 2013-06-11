includes ArrayList;

configuration ArrayListTestC {
} implementation {
	components Main,
		ArrayListM,
		ArrayListTestM;

	Main.StdControl -> ArrayListM;
	Main.StdControl -> ArrayListTestM;

	ArrayListTestM.ArrayList->ArrayListM.ArrayList[ARRAY_LIST_EVENT_META];
}
