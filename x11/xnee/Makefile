# New ports collection makefile for:	xnee
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xnee
PORTVERSION=	2.05
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Xnee-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X events recorder and player

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --enable-cli --disable-doc

MAN1=		cnee.1
INFO=		xnee
PLIST_FILES=	bin/cnee \
		share/Xnee/example1.xns \
		share/Xnee/simple_bash.sh \
		share/Xnee/xnee.sh
PLIST_DIRS=	share/Xnee

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/gnee
PKGNAMESUFFIX=	-gtk
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|make man|$$(MAKE) man|g' ${WRKSRC}/cnee/Makefile.in

post-build:
	cd ${WRKSRC}/doc && ${LOCALBASE}/bin/makeinfo --no-split xnee.texi

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xnee.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>
