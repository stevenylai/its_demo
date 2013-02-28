configuration FusionPointC {
	provides {
		interface StdControl;
		interface FusionPoint;
	}
} implementation {
	components
		FusionPointM;

	StdControl = FusionPointM.StdControl;
	FusionPoint = FusionPointM.FusionPoint;
}
