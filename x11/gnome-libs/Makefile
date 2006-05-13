# New ports collection makefile for:	gnomelibs
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomelibs
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES?=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-libs/1.4
DISTNAME=	gnome-libs-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	Libraries for GNOME, a GNU desktop environment

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix esound gtk12 imlib libxml orbit
INSTALLS_SHLIB=	yes
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

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/gnome-config.in ${WRKSRC}/libgnome/gnome-util.c

# need to make launched gnome-terminals appear in utmp/wtmp
.if !target(post-install)
post-install:
	@${CHMOD} u+s ${PREFIX}/bin/gnome-pty-helper
.endif

.include <bsd.port.mk>
