# ex:ts=8
# New ports collection makefile for:	xdialog
# Date created:			Jan 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xdialog
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://thgodef.nerim.net/xdialog/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drop in replacement for the "dialog" or "cdialog" programs

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	Xdialog.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| install-docDATA||g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
