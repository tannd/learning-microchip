library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity nt_nt is
	 port(
		 clk : in std_logic;
		 SI : in BIT;
		 SO : out BIT
	     );
end nt_nt;

architecture nt_nt of nt_nt is
	signal tmp: bit_vector(7 downto 0); 
begin 
    process (clk) 
      begin 
		if (clk'event and clk='1') then  
          tmp <= tmp(6 downto 0)& SI; 
        end if; 
    end process; 
    SO <= tmp(7); 
end nt_nt;
--clk=20Mhz; SI= random 10ns;