import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;

class Solution {
    private LocalDateTime time;
    
    private LocalDateTime videoEndTime;
    private LocalDateTime opStartTime;
    private LocalDateTime opEndTime;
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        initTime(pos, video_len, op_start, op_end);
        System.out.println("time = " + time);
        
        shiftTimeifOpening();
        
        for (String command : commands) {
            Command c = Command.fromString(command);
            System.out.println("command: " + c.getValue());
            
            calcTime(c);
            System.out.println("cur ===> " + printResult());
            
            shiftTimeifOpening();
        }
        
        return printResult();
    }
    
    private void initTime(String pos, String videoLen, String opStart, String opEnd) {
        int[] times = parseTimeFormat(pos);
        time = LocalDateTime.of(2024, 11, 24, 0, times[0], times[1]);
        
        times = parseTimeFormat(videoLen);
        videoEndTime = LocalDateTime.of(2024, 11, 24, 0, times[0], times[1]);
        
        times = parseTimeFormat(opStart);
        opStartTime = LocalDateTime.of(2024, 11, 24, 0, times[0], times[1]);
        
        times = parseTimeFormat(opEnd);
        opEndTime = LocalDateTime.of(2024, 11, 24, 0, times[0], times[1]);
    }
    
    private void shiftTimeifOpening() {
        if ((time.isEqual(opStartTime) || time.isAfter(opStartTime)) && time.isBefore(opEndTime)) {
            time = LocalDateTime.of(2024, 11, 24, 0, opEndTime.getMinute(), opEndTime.getSecond());
        }
    }
    
    private void calcTime(Command command) {
        switch (command) {
            case PREV:
                if (time.getMinute() == 0 && time.getSecond() <= 10) {
                    time = time.minusSeconds(time.getSecond());
                } else {
                    time = time.minusSeconds(10);
                }
                break;
            case NEXT:
                if (videoEndTime.isBefore(time.plusSeconds(10))) {
                    time = LocalDateTime.of(2024, 11, 24, 0, videoEndTime.getMinute(), videoEndTime.getSecond());
                } else {
                    time = time.plusSeconds(10);
                }
        }
    }
    
    private int[] parseTimeFormat(String input) {
        String[] values = input.split(":");
        
        Integer minute = Integer.parseInt(values[0]);
        Integer second = Integer.parseInt(values[1]);
        
        int[] result = {minute, second}; 
        return result;
    }
    
    private String printResult() {
        return time.format(DateTimeFormatter.ofPattern("mm:ss"));
    }
    
    private enum Command {
        PREV("prev"),
        NEXT("next")
        ;
        
        private String value;
        
        Command(String value) {
            this.value = value;
        }
        
        public static Command fromString(String str) {
            for (Command command : values()) {
                if (command.getValue().equals(str)) {
                    return command;
                }
            }
            
            throw new IllegalArgumentException("존재하지 않는 값입니다.");
        }
        
        public String getValue() {
            return this.value;
        }
    }
}