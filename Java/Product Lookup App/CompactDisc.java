public class CompactDisc extends Product
{
	private String artist;

	public CompactDisc()
	{
		super();
		artist = "";
		count++;
	}

	public void setArtist(String artist)
	{
		this.artist = artist;
	}

	public String getArtist(){
		return artist;
	}

	public String toString()
	{
		return super.toString() +
			"Artist:      " + artist + "\n";
	}
}