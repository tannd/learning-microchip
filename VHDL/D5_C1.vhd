
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D5_C1 is
	generic (n:integer:=8);
	 port(
		 clk : in STD_LOGIC;
		 sel : in STD_LOGIC;
		 SI : in bit;
		 Q : out bit_VECTOR(n-1 downto 0)
	     );
end D5_C1;

--}} End of automatically maintained section

architecture D5_C1 of D5_C1 is
	signal temp:bit_vector(n-1 downto 0); 
  begin 
    process (clk,SI) 
      begin  
        if (clk'event and clk='1') then  
          temp <= temp(n-2 downto 0)& SI; 
        end if; 	  
    end process; 
	process(sel,clk)
	begin	
		if (rising_edge(clk))then
		if (sel='1') then Q(0)<=temp(n-1);
		else 
			if (sel='0') then Q<=temp;
			end if;
		end if;
		end if;
	end process;
end D5_C1;
