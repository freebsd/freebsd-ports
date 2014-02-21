# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-theme-switch
PORTVERSION=	1.0.1
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://www.muhri.net/
PKGNAMESUFFIX=	1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool for switching GTK+ themes

USE_GNOME=	gtk12
USES=		gmake

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}/README
.endif

.include <bsd.port.mk>
