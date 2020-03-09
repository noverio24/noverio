
package Classes;

import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Hashtable;

/**
 *
 * @author Zahid
 */
abstract public class Question {
    
    private int type;
    private String content;
    private Dictionary options;
    private int correctAnswer;
    private int selectedAnswer;
    private boolean isAttempted;
    private boolean isCorrect;
    private int marks;
    private String lecturerName;
    
    public Question(int _type,String _content){
        
        this.type = _type;
        this.content = _content;
        this.isAttempted = false;
    
    }
    
    public String getContent() {
        return content;
    }

    public Dictionary getOptions() {
        return options;
    }

    public boolean isAttempted() {
        return isAttempted;
    }
    
    public void setAttempted(boolean status){
        this.isAttempted = status;
    }

    public boolean isCorrect() {
        return isCorrect;
    }
    
    public int getType(){
        return this.type;
    }

    public void setIsCorrect(boolean isCorrect) {
        this.isCorrect = isCorrect;
    }
    
    public String lecturerName(){
        return this.lecturerName;
    }
    
   

   abstract public String getOption(int index);
   
}
