import java.util.*;

class checkPerm{
	static boolean permutationVer1(String s,String t){
		if(s.length()!=t.length()){
			return false;
		}
		int [] letter = new int[128]; //assumption
		char[] s_array = s.toCharArray();
		for(char ch : s_array){
			letter[ch]++;
		}
		for(int i=0;i<t.length();i++){
			int c = (int)t.charAt(i);
			letter[c]--;
			if(letter[c] <0)
				return false;
		}
		return true;
	}
	static String sort(String str){
		char[] content = str.toCharArray();
		Arrays.sort(content);
		return new String(content);
	}
	static boolean permutation(String s, String t){
		if(s.length() != t.length())
			return false;
		return sort(s).equals(sort(t));
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		if(permutation(s,t)){
			System.out.println("one String is permutaion of other");
		}
		else{
			System.out.println("not permutation of each other");
		}
		System.out.println("Version 1");
		if(permutationVer1(s,t)){
                        System.out.println("one String is permutaion of other");
                }
                else{
                        System.out.println("not permutation of each other");
                }
	}
}
