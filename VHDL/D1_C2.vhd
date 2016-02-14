library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D1_C2 is
	 port(
		 clk : in STD_LOGIC;
		 rst : in STD_LOGIC;
		 q0 : out STD_LOGIC;
		 q1 : out STD_LOGIC
	     );
end D1_C2;

--}} End of automatically maintained section

architecture D1_C2 of D1_C2 is
signal j : integer:=1;
begin  
	process(clk,rst)
	begin  
		if rst ='0' then j<=0;
		else
		if rising_edge(clk) then	   
			if j=3 then j<=0;
			else
				j<=j+1;	
		    end if;
	    end if;	
		end if;
	end process;
	process(rst,j)
	begin 
		if rst ='0' then q0<='0';q1<='0';
		else
			if j=1 then q0<='1';q1<='1';  end if;		
			if j=3 then q0<='0';q1<='0';  end if ;
			end if;
			end process;
end led;
-- clk =2hz
