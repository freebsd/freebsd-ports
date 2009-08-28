# ex:ts=8
# New ports collection makefile for:	xdialog
# Date created:			Jan 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xdialog
PORTVERSION=	2.3.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://thgodef.nerim.net/xdialog/ \
  		LOCAL/chinsan
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drop in replacement for the "dialog" or "cdialog" programs

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		Xdialog.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|m4 lib src|m4 src|g ; \
		 s|-I../lib||g ; \
		 s|-L../lib -lgetopt||g ; \
		 s| install-docDATA||g'
	@${REINPLACE_CMD} -e 's,Xdialog\\-%%version%%,xdialog,' \
		${WRKSRC}/doc/Xdialog.man

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/samples
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${DOCSDIR}/samples
.endif

.include <bsd.port.mk>
