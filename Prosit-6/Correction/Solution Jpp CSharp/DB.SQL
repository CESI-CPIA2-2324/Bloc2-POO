------------------------------
-- SCHEMA
------------------------------
USE [master]
GO
/****** Object:  Database [Prosit6Database]    Script Date: 25/11/2021 11:17:54 ******/
CREATE DATABASE [Prosit6Database]
GO
USE [Prosit6Database]
GO
/****** Object:  Table [dbo].[Adresse]    Script Date: 25/11/2021 11:17:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Adresse](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[CodePostal] [nvarchar](10) NOT NULL,
	[Ville] [nvarchar](50) NOT NULL,
	[PersonneId] [int] NOT NULL,
 CONSTRAINT [PK_Adresse] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Personne]    Script Date: 25/11/2021 11:17:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Personne](
	[Id] [int] IDENTITY(1,1)  NOT NULL,
	[Nom] [nvarchar](50) NOT NULL,
	[Prenom] [nvarchar](50) NULL,
 CONSTRAINT [PK_Personne] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Adresse]  WITH CHECK ADD  CONSTRAINT [FK_Adresse_Personne] FOREIGN KEY([PersonneId])
REFERENCES [dbo].[Personne] ([Id])
GO
ALTER TABLE [dbo].[Adresse] CHECK CONSTRAINT [FK_Adresse_Personne]
GO
------------------------------
-- DATA
------------------------------
-- Personne
SET IDENTITY_INSERT [dbo].[Personne] ON 
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (1, N'Durand', N'Jean')
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (2, N'Dupond', N'Pierre')
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (3, N'Martin', N'Jacques')
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (4, N'Petit', N'Paul')
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (5, N'Dubois', N'Mathieu')
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (6, N'Robert', N'Marc')
GO
INSERT [dbo].[Personne] ([Id], [Nom], [Prenom]) VALUES (7, N'Moreau', N'Luc')
GO
SET IDENTITY_INSERT [dbo].[Personne] OFF
GO
-- Adresse
SET IDENTITY_INSERT [dbo].[Adresse] ON 
GO
INSERT [dbo].[Adresse] ([Id], [CodePostal], [Ville], [PersonneId]) VALUES (1, N'34130', N'Mauguio', 1)
GO
INSERT [dbo].[Adresse] ([Id], [CodePostal], [Ville], [PersonneId]) VALUES (2, N'34130', N'Lansargues', 1)
GO
INSERT [dbo].[Adresse] ([Id], [CodePostal], [Ville], [PersonneId]) VALUES (4, N'34131', N'Mauguio Cedex', 1)
GO
INSERT [dbo].[Adresse] ([Id], [CodePostal], [Ville], [PersonneId]) VALUES (6, N'34000', N'Montpellier', 2)
GO
INSERT [dbo].[Adresse] ([Id], [CodePostal], [Ville], [PersonneId]) VALUES (7, N'34100', N'Montpellier Centre', 2)
GO
INSERT [dbo].[Adresse] ([Id], [CodePostal], [Ville], [PersonneId]) VALUES (8, N'66000', N'Perpignan', 3)
GO
SET IDENTITY_INSERT [dbo].[Adresse] OFF
GO