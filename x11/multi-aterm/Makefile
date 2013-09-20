# Created by: Sebastian Yepes <esn@x123.info>
# $FreeBSD$

PORTNAME=	multi-aterm
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/materm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi terminal based on aterm

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-xpm=${LOCALBASE}

DOCS=		AUTHORS ChangeLog INSTALL TODO
MAN1=		multi-aterm.1

.if defined(WITH_UTMP)
CONFIGURE_ARGS+=	--enable-utmp
.endif

.if defined(WITH_WTMP)
CONFIGURE_ARGS+=	--enable-wtmp
.endif

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can specify the following options:"
	@${ECHO_MSG} "WITH_UTMP=yes - enable utmp support"
	@${ECHO_MSG} "WITH_WTMP=yes - enable wtmp support"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
