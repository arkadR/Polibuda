﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SO_zad4
{
	class Rowny : IAllocationAlgorithm
	{
		int pageCount;
		Process[] processes;

		public void Initialize(int pageCount, Process[] processes)
		{
			this.pageCount = pageCount;
			this.processes = processes;
			for (int i = 0; i < processes.Length; i++)
				processes[i] = new Process(processes[i]);

			///ASSIGN FRAMES
			int Single = pageCount / processes.Length;
			int Mod = pageCount % processes.Length;
			for (int i = 0; i < Mod; i++)
				processes[i].AssignFrames(Single + 1);
			for (int i = Mod; i < processes.Length; i++)
				processes[i].AssignFrames(Single);
		}
		
		public int Run()
		{
			int PageFaults = 0;
			foreach (Process p in processes)
			{
				PageFaults += p.Run();
			}
			return PageFaults;
		}
	}
}
