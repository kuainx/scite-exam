interface Instrument {
	void play(String musicName);
}

class NationalInstrument implements  Instrument {  
	private String instrumentName;

	NationalInstrument(String instrumentName) {
		this.instrumentName = instrumentName;
	}

	public void NationalInstrument() {
	}

	public String getInstrumentName() {
		return instrumentName;
	}

	public void setInstrumentName(String instrumentName) {
		instrumentName = instrumentName;
	}

	void play(String musicName) {    
		System.out.println(instrumentName + ":" + musicName);
	}
}

public class GC3 {
	public static void main(String[] args) {
		NationalInstrument instrument1 = new NationalInstrument();
		instrument1.setInstrumentName("����");
		instrument1.play("ʮ�����");     
		NationalInstrument instrument2 = new NationalInstrument();
		instrument2.play("��Ȫӳ��");
	}
}
