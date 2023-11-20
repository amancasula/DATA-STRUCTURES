import java.util.*;
import java.util.stream.Collectors.*;
import java.util.stream.*;

public class Heap{


  int[] heap = new int[100];
  
  int last = 1;
  
  int temp = 0;
  
  int count = 0;
  
  public static void main(String[] args){
    
    Heap h = new Heap();
    for(int i=0; i<h.heap.length; i++){
  
    //System.out.println(heap[i]);
      h.heap[i] = -1;
      }
    
    
    
    
    while(true){
    
      System.out.println("Type Insert(I) OR Delete(D)");
      Scanner sc = new Scanner(System.in);
      String ip = sc.next();
      
      if( ip.equals("I")){
        System.out.println("  Enter Element: ");
        int element = sc.nextInt();
        sc.nextLine();
        h.insert(element);
      }
    
      else if(ip.equals("D")){
        h.delTop();
        }
     
      else if(ip.equals("print")){
        h.print();
      }
     
     
     else if(ip.equals("sort")){
        h.mysort();
        return;
      }
        
      else if(ip.equals("/exit")){
        return;
      }
      System.out.println(Arrays.stream(h.heap).boxed().skip(1).limit(h.last-1).collect(Collectors.toList()));
    }
  }
  
  
  void insert(int num){
  
    if(last >= heap.length){
    
      System.out.println("HEAP FULL!");
      
      return;
      
      }
    
    count++;
    
    heap[last] = num;
    
    int child = last;
    
    int parent = (int)Math.floor(child/2);
    
    last++;
    
    while(child > 1){
    
      if (heap[parent] > heap[child]){
        
        temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;
        
        }
        
      child = parent;
      parent = (int)Math.floor(child/2);
      }
      
    }
    
    
  void delTop(){
  
    if(last <= 1){
    
      System.out.println("HEAP EMPTY!");
      
      return;
      
      }
  
    temp = heap[last-1];  
    heap[last-1] = heap[1];
    heap[1] = temp;
    last--;
    
    int parent = 1;
    int child1 = 2;
    int child2 = 3;
    int min_child = 0;
    
    while(child1 < last){
    
    
      if(child2 <  last){
      if(heap[child1] > heap[child2]){
        min_child = child2;
        }
      else{
        min_child = child1;
      }
      }
      else if(child1 < last && child2 == last){
        
        min_child = child1;
        
        } 
      
      
      
      if( heap[parent] > heap[min_child]){
      
        temp = heap[parent];
        heap[parent] = heap[min_child];
        heap[min_child] = temp;
        
        }
        
        parent = min_child;
        child1 = 2*parent;
        child2 = child1+1;
      }
        
   }
   
   void print(){
   
     int i = 1;
     while( heap[i] != -1){
       System.out.print(heap[i]+" ");
       i++;
        }
     } 
     
     void mysort(){
   
     int loccount = 1;
     while(loccount <= count){
       delTop();
       loccount++;
        }
     print();
     }
}     

 
    
      
    
    
    
    
    
        
    
    
  
    
  
  
    
    
  
  
