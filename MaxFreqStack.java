package maxfreqstack;

import java.util.*;

class Node implements Comparable<Node>
{
    int val, freq, timer;
    Node(int val, int freq, int timer)
    {
        this.val = val;
        this.freq = freq;
        this.timer = timer;
    }
    
    public int compareTo(Node nd)
    {
        if(freq==nd.freq)
            return nd.timer-timer;
        else
            return nd.freq - freq;
    }
}

class FreqStack {
    PriorityQueue<Node>pq; int timer;
    HashMap<Integer, Integer>freq;
    public FreqStack() {
        pq = new PriorityQueue<Node>(); timer = 0;
        freq = new HashMap<Integer, Integer>();
    }
    
    public void push(int val) {
        int cnt = freq.get(val)==null?0:freq.get(val);
        cnt++; freq.put(val, cnt);
        pq.add(new Node(val, cnt, timer)); timer++;
    }
    
    public int pop() {
        Node nd = pq.poll();
        int cnt = nd.freq; cnt--;
        freq.put(nd.val, cnt); return nd.val;
    }
}


public class MaxFreqStack {
    public static void main(String[] args) {
        FreqStack fs = new FreqStack();
        fs.push(10);
        fs.push(10);
        fs.push(101);
        fs.push(11);
        fs.push(12);
        fs.push(1);
        fs.push(5);
        fs.push(100);
        
        System.out.println(fs.pop());
        System.out.println(fs.pop());
        System.out.println(fs.pop());
        
    }
}
