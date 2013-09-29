package itransnet_base.tracking.Server.Message;

public class UnknownMessageException extends Exception
{
	public UnknownMessageException ()
	{
		super ("Message type not recognized by system!!");
	}
}