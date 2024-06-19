resize(n)  
vector扩容至n，不是按倍数扩容


push_back    insert
改变vector的size，当n大于capacity时，vector会进行扩容（gcc2倍，MSVC1.5倍）


reserve(n)   
改变vector的capacity，当小于capacity时，什么也不发生；当n大于capacity时，会将capacity变大为n



为什么扩容？