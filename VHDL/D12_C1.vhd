library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D12_C1 is
	 port(
		 load : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 d : in STD_LOGIC_VECTOR(7 downto 0);
		 dout : out STD_LOGIC
	     );
end D12_C1;

architecture D12_C1 of D12_C1 is
signal t:std_logic;
signal temp:std_logic_vector(7 downto 0);
begin
	process(clk,load,d)	
	begin
	if (load ='1') then temp<=d;
	elsif (rising_edge(clk)) then 
		t<=temp(7);
		temp(7 downto 1)<= temp(6 downto 0);
		temp(0)<='0';
	end if;
	end process;
	dout<=t;
	
end D12_C1;
--load 500khz;clk=20Mhz;	d counter 0-11111111 binary 125 ns;