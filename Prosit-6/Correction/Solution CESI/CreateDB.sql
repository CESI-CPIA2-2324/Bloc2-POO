USE [master]
GO
/****** Object:  Database [Workshop]    Script Date: 26/11/2021 08:57:25 ******/
CREATE DATABASE [Workshop]
GO
USE [Workshop]
GO
/****** Object:  Table [dbo].[TB_ADRESSE]    Script Date: 26/11/2021 08:57:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TB_ADRESSE](
	[id_adresse] [int] NOT NULL,
	[adresse] [nvarchar](100) NULL,
	[ville] [nvarchar](100) NULL,
	[cp] [nvarchar](100) NULL,
	[id_personne] [int] NULL,
 CONSTRAINT [PK_TB_ADRESSE] PRIMARY KEY CLUSTERED 
(
	[id_adresse] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TB_PERSONNE]    Script Date: 26/11/2021 08:57:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TB_PERSONNE](
	[id_personne] [int] NOT NULL,
	[nom] [nvarchar](100) NOT NULL,
	[prenom] [nvarchar](100) NULL,
 CONSTRAINT [PK_TB_PERSONNE] PRIMARY KEY CLUSTERED 
(
	[id_personne] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[TB_ADRESSE] ([id_adresse], [adresse], [ville], [cp], [id_personne]) VALUES (1, N'Adresse1', N'Ville1', N'Cp1', 1)
GO
INSERT [dbo].[TB_ADRESSE] ([id_adresse], [adresse], [ville], [cp], [id_personne]) VALUES (2, N'Adresse2', N'Ville2', N'Cp2', 2)
GO
INSERT [dbo].[TB_ADRESSE] ([id_adresse], [adresse], [ville], [cp], [id_personne]) VALUES (3, N'Adresse3', N'Ville3', N'Cp3', 1)
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (1, N'Nom1', N'Prenom1')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (2, N'Nom2', N'Prenom2')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (3, N'Nom3', N'Prenom3')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (4, N'Nom4', N'Prenom4')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (5, N'Nom5', N'Prenom5')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (6, N'Nom6', N'Prenom6')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (7, N'Nom7', N'Prenom7')
GO
INSERT [dbo].[TB_PERSONNE] ([id_personne], [nom], [prenom]) VALUES (9, N'Nom9', N'Prenom9')
GO
USE [master]
GO
ALTER DATABASE [Workshop] SET  READ_WRITE 
GO
