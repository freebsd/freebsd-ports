# New ports collection makefile for:	KDE4
# Date created:				Feb 28 2008
# Whom:					Will Andrews <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	kde4
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	The "meta-port" for KDE

OPTIONS=	KDEACCESSIBILITY "Accessibility applications" on \
		KDEADMIN "KDE Administration applications" on \
    		KDEARTWORK "Additional themes, sounds, etc" on \
		KDEGAMES "Games like kolf, patience, atlantik, etc" on \
		KDEEDU "Educational applications" on \
		KDEGRAPHICS "Graphics utilities like kview, kpaint, etc" on \
		KDENETWORK "Network-related programs like kopete, etc" on \
		KDEMULTIMEDIA "Multimedia utilities like noatun, etc" on \
		KDEPIM "Personal Information Management: mail, etc" on \
		KDEPLASMA "Extra plasmoids for KDE" on \
		KDESDK "KDE software development kit" on \
		KDETOYS "Miscellaneous small applications" on \
		KDEUTILS "Utilities like kcalc, kcharselect, etc" on \
		KDEWEBDEV "Website development environment" on \
		XINE "Xine backend for Phonon" on

USE_KDE4=	kdelibs kdebase pimlibs workspace kdeprefix runtime oxygen
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KDEACCESSIBILITY)
RUN_DEPENDS+=	kdeaccessibility>=4:${PORTSDIR}/accessibility/kdeaccessibility4
.endif
.if !defined(WITHOUT_KDEADMIN)
RUN_DEPENDS+=	kdeadmin>=4:${PORTSDIR}/sysutils/kdeadmin4
.endif
.if !defined(WITHOUT_KDEARTWORK)
RUN_DEPENDS+=	kdeartwork>=4:${PORTSDIR}/x11-themes/kdeartwork4
.endif
.if !defined(WITHOUT_KDEGAMES)
RUN_DEPENDS+=	kdegames>=4:${PORTSDIR}/games/kdegames4
.endif
.if !defined(WITHOUT_KDEEDU)
RUN_DEPENDS+=	kdeedu>=4:${PORTSDIR}/misc/kdeedu4
.endif
.if !defined(WITHOUT_KDEGRAPHICS)
RUN_DEPENDS+=	kdegraphics>=4:${PORTSDIR}/graphics/kdegraphics4
.endif
.if !defined(WITHOUT_KDENETWORK)
RUN_DEPENDS+=	kdenetwork>=4:${PORTSDIR}/net/kdenetwork4
.endif
.if !defined(WITHOUT_KDEMULTIMEDIA)
RUN_DEPENDS+=	kdemultimedia>=4:${PORTSDIR}/multimedia/kdemultimedia4
.endif
.if !defined(WITHOUT_KDEPIM)
RUN_DEPENDS+=	kdepim>=4:${PORTSDIR}/deskutils/kdepim4
.endif
.if !defined(WITHOUT_KDEPLASMA)
RUN_DEPENDS+=	kdeplasma-addons>=4:${PORTSDIR}/deskutils/kdeplasma-addons
.endif
.if !defined(WITHOUT_KDETOYS)
RUN_DEPENDS+=	kdetoys>=4:${PORTSDIR}/x11-clocks/kdetoys4
.endif
.if !defined(WITHOUT_KDESDK)
RUN_DEPENDS+=	kdesdk>=4:${PORTSDIR}/devel/kdesdk4
.endif
.if !defined(WITHOUT_KDEUTILS)
RUN_DEPENDS+=	kdeutils>=4:${PORTSDIR}/misc/kdeutils4
.endif
.if !defined(WITHOUT_KDEWEBDEV)
RUN_DEPENDS+=	kdewebdev>=4:${PORTSDIR}/www/kdewebdev4
.endif
.if !defined(WITHOUT_XINE)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_xine.so:${PORTSDIR}/multimedia/phonon-xine
.endif

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
