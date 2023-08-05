package test;
interface Instrument {
	void play(String musicName);
}

class NationalInstrument implements  Instrument {  
	private String instrumentName;

	NationalInstrument(String instrumentName) {
		this.instrumentName = instrumentName;
	}

	NationalInstrument() {//...
	}

	public String getInstrumentName() {
		return instrumentName;
	}

	public void setInstrumentName(String instrumentName) {
		this.instrumentName = instrumentName;//...
	}

	public void play(String musicName) {    //...
		System.out.println((instrumentName==null?"二胡":instrumentName) + ":" + musicName);//...
	}
}

public class GC3 {
	public static void main(String[] args) {
		NationalInstrument instrument1 = new NationalInstrument();
		instrument1.setInstrumentName("琵琶");
		instrument1.play("十面埋伏");     
		NationalInstrument instrument2 = new NationalInstrument();
		instrument2.play("二泉映月");
	}
}
