# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	wmmatrix
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/ \
		http://ia300205.us.archive.org/0/items/tucows_10414_WMMatrix/
DISTNAME=	wmMatrix-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DockApp that runs a version of the xmatrix screenhack

MAKE_JOBS_UNSAFE= yes

PLIST_FILES=	bin/wmmatrix
USES=		gmake xorg
USE_XORG=	xpm
ALL_TARGET=	clean all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmMatrix ${STAGEDIR}${PREFIX}/bin/wmmatrix

.include <bsd.port.mk>
