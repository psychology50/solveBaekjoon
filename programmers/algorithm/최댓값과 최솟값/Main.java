class Solution {
    public String solution(String s) {
        String answer = "";
        String[] strArr = s.split(" ");
        
        int[] intArr = new int[strArr.length];
        
        for(int i=0; i<strArr.length; i++){
            intArr[i] = Integer.parseInt(strArr[i]);
        }
        
        int max = intArr[0];
        int min = intArr[0];
        
        for(int i=0; i<intArr.length; i++){
            if(intArr[i]>max){
                max = intArr[i];
            }
            if(intArr[i]<min){
                min = intArr[i];
            }
        }
        answer = min+" "+max;
        
        return answer;
    }
}