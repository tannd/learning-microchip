
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity nt_ss is
	 port(
		 clk : in STD_LOGIC;
		 SI : in bit;
		 PO : out bit_VECTOR(7 downto 0)
	     );
end nt_ss;

--}} End of automatically maintained section

architecture nt_ss of nt_ss is
	signal tmp:bit_vector(7 downto 0); 
  begin 
    process (clk) 
      begin  
        if (clk'event and clk='1') then  
          tmp <= tmp(6 downto 0)& SI; 
        end if; 
		 PO <= tmp;
    end process; 
 
end nt_ss;
--clk=20Mhz; SI= random