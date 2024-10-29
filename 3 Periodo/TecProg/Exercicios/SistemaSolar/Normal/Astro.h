#ifndef ASTRO_H
#define ASTRO_H

class Astro{

	protected:
		int NA;


	public:
		Astro() {NA = 0;}
		~Astro(){}
		void setNA(int na){NA = na;}
		int getNA(){return NA;}
};


#endif
