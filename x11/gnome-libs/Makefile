# New ports collection makefile for:	gnomelibs
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-libs/Makefile,v 1.7 2007/08/04 03:51:32 marcus Exp $
#

PORTNAME=	gnome-libs
PORTVERSION=	1.4.2
PORTREVISION=	16
CATEGORIES?=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	Libraries for GNOME, a GNU desktop environment

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_BZIP2=	yes
USE_XORG=	xpm ice x11
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix esound gtk12 imlib libxml orbit
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		dns-helper.1 gconfigger.1 gnome-bug.1 gnome-config.1 \
		gnome-doc.1 gnome-dump-metadata.1 gnome-gen-mimedb.1 \
		gnome-mkstub.1 gnome-moz-remote.1 gnome-name-service.1 \
		gnome-pty-helper.1 gnome.1 gnome_segv.1 goad-browser.1 \
		libart-config.1 loadshlib.1 new-object.1
MAN5=		gnome-mime.5

DOCSDIR=	${PREFIX}/share/doc/gnomelibs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/gnome-config.in ${WRKSRC}/libgnome/gnome-util.c
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure \
		${WRKSRC}/libart_lgpl/configure

# need to make launched gnome-terminals appear in utmp/wtmp
.if !target(post-install)
post-install:
	@${CHMOD} u+s ${PREFIX}/bin/gnome-pty-helper
.endif

.include <bsd.port.mk>
